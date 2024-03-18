from typing import DefaultDict

s = input()
numProductionRules = int(input())
rules = DefaultDict(list)
for n in range(numProductionRules):
    xy = input().split()
    rules[xy[0]] = xy[1]
numIteractions = int(input())
for n in range(numIteractions):
    newS = ""
    for c in s:
        if c in rules:
            newS += rules[c]
        else:
            newS += c
    s = newS
print(s)