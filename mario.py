from cs50 import get_int
while True:
    n = get_int("Height: ")
    if n > 0 and n < 9:
        break

# for row
for i in range(n):
    # for blankspace
    for j in range(n-i-1):
        print(" ", end="")
    # for hashes
    for k in range(i+1):
        print("#", end="")
    # for new line
    for l in range(1):
        print("")