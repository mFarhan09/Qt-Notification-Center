import uiautomation as auto
import json
import time
from datetime import datetime

seen = set()

while True:
    try:
        desktop = auto.GetRootControl()

        for ctrl, depth in auto.WalkControl(desktop, maxDepth=5):
            if ctrl.ControlTypeName == 'TextControl' and ctrl.Name:
                content = ctrl.Name.strip()

                if content and content not in seen:
                    seen.add(content)

                    # Basic source classification
                    source = "Others"
                    if "WhatsApp" in content:
                        source = "WhatsApp"
                    elif "gmail" in content or "@gmail.com" in content:
                        source = "Email"
                    elif "YouTube" in content:
                        source = "YouTube"

                    now = datetime.now().isoformat()
                    msg = {
                        "source": source,
                        "title": f"{source} Notification",
                        "message": content,
                        "timestamp": now
                    }

                    print(json.dumps(msg), flush=True)

        time.sleep(2)

    except Exception as e:
        print(f"Error: {str(e)}", flush=True)
        time.sleep(2) 