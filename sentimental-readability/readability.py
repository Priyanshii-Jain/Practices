import cs50
import math

# prompt the user for data input
text = cs50.get_string("Text: ")

# to count no. of letters
letters = 0
for i in range(len(text)):
    if text[i].isalpha():
        letters += 1
        # print(f"{letters}")

# to count no. of words
words = 1
for i in range(len(text)):
    if text[i].isspace():
        words += 1
       # print(f"{words}")

# to count no. of sentences
sentences = 0
for i in range(len(text)):
    if text[i] == "." or text[i] == "?" or text[i] == "!":
        sentences += 1
        # print(f"{sentences}")

# convert int into floats
T = letters
D = words
C = sentences
# print(f"{T}, {D}, {C}")

# count letters per 100 word and sentences per 100 words
L = float(T / D * 100)
S = float(C / D * 100)
# print(f"{L} {S}")

# apply formula
index = (0.0588 * L - 0.296 * S - 15.8)
# print(f"{index}")
ans = round(index)
# print(f"{ans}")

# print the grade
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {ans}")
