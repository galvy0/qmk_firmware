from qmk.info import validate_keyboard
import json, sys
p='keyboards/galvy/jd45_alpha/keyboard.json'
data=json.load(open(p))
validate_keyboard(data, p)
print('VALID')
