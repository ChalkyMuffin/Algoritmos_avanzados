C = []
with open("coins-n5.txt", "r") as file:
    for line in file:
        row = [int(num) for num in line.split()]
        C.append(row)

print(C)
#for row in C:
#    print(C)