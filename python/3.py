import re


with open("../data/3.txt") as file:
    content = file.read()

pattern = re.compile(r"(mul\((\d{1,3}),(\d{1,3})\))|(do\(\))|(don't\(\))")
matches = pattern.findall(content)

enabled = True
part_1, part_2 = 0, 0

for match in matches:
    if match[3]:
        enabled = True
        continue

    if match[4]:
        enabled = False
        continue

    if not match[0]:
        continue

    value = int(match[1]) * int(match[2])
    part_1 += value

    if not enabled:
        continue

    part_2 += value

print(part_1)  
# >>> 173517243
print(part_2)  
# >>> 100450138
