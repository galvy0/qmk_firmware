import json
import sys

try:
    import jsonschema
except Exception:
    print('MISSING: python package "jsonschema" is required. Install with: pip install jsonschema')
    sys.exit(2)

schema = json.load(open('data/schemas/keyboard.jsonschema'))
kb = json.load(open(sys.argv[1]))

try:
    jsonschema.validate(kb, schema)
    print('VALID')
except Exception as e:
    print('INVALID')
    print(e)
    sys.exit(3)
