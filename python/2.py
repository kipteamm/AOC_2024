def are_valid(reports: list, sorted_reports: list) -> bool:
    previous = reports[0]

    for i in range(1, len(reports)):
        if reports[i] != sorted_reports[i]:
            return False
        
        difference = abs(reports[i] - previous)
        if difference < 1 or difference > 3:
            return False
        
        previous = reports[i]
        
    return True


safe = 0
for line in open("../data/2.txt").read().splitlines():
    reports = list(map(int, line.split(" ")))
    sorted_repots = sorted(reports)

    if are_valid(reports, sorted_repots):
        safe += 1
        continue

    sorted_repots.reverse()
    safe += int(are_valid(reports, sorted_repots))

print(safe)