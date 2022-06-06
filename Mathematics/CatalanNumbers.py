n=int(input())
list=[1]
for i in range(1,n+1):
    num=0
    for j in range(1,i+1):
        num+=list[j-1]*list[i-j]
    list.append(num)
print(list[n])