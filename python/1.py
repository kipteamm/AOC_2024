lines = open("../data/1.txt").read().splitlines()
first_column, last_column = [], []

for line in lines:
    x, y = line.split()
    first_column.append(int(x))
    last_column.append(int(y))

first_column.sort()
last_column.sort()

total = 0
for i in range(len(first_column)):
    total += abs(first_column[i] - last_column[i])

similarity = 0
for x in first_column:
    similarity += x * last_column.count(x)

print(total)
print(similarity)