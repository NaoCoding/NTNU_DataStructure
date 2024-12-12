a =  [56, 12, 98, 34, 87, 65, 23, 45, 78, 11, 89, 32, 7, 53, 41]
print(sorted(a))

b = [56, 12, 98, 34, 87, 65, 23, 45, 78, 11, 89, 32, 7, 53, 41]
c = [[] for i in range(10)]
for i in b:
    c[i//10].append(i)
print(c)
print("".join([",".join([str(d) for d in i]) for i in c]))