import firebase_admin
from firebase_admin import credentials, firestore

def get_ai_prediction(node_id, current_reading):
    moisture = current_reading.get('moisture_pct', 0)
    if moisture < 65:
        duration = round((75 - moisture) * 0.5)
        return True, min(duration, 30)
    return False, 0
