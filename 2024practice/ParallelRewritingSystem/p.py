from typing import DefaultDict

#input parsing
s = input()
numProductionRules = int(input())
rules = DefaultDict(list)
for n in range(numProductionRules):
    x,y = input().split()
    rules[x] = y
numIteractions = int(input())

#applying the rules 
for n in range(numIteractions):
    s = ''.join([rules.get(c, c) for c in s])

print(s)