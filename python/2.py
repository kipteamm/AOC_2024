def safe(reports: list) -> bool:
    sorted_reports = sorted(reports)

    if not (reports == sorted_reports or reports == list(reversed(sorted_reports))):
        return False

    return not any(a == b or abs(a - b) > 3 for a, b in zip(reports, reports[1:]))

part_1, part_2 = 0, 0
for line in open("../data/2.txt").read().splitlines():
    reports = list(map(int, line.split(" ")))

    if safe(reports):
        part_1 += 1
        part_2 += 1
        continue

    for item in range(len(line)):
        if safe(reports[:item] + reports[item + 1:]):
            part_2 += 1
            break

print(part_1)
# >>> 369
print(part_2)
# >>> 428