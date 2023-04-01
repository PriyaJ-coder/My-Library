rows = int(input("Enter K Shape Alphabets Pattern Rows = "))

print("====K Shape Alphabets Pattern====")

i = rows - 1
while (i >= 0):
    alphabet = 65
    j = 0
    while (j <= i):
        print('%c' % (alphabet + j), end=' ')
        j = j + 1
    print()
    i = i - 1

i = 1
while (i < rows):
    alphabet = 65
    j = 0
    while (j <= i):
        print('%c' % (alphabet + j), end=' ')
        j = j + 1
    print()
    i = i + 1
