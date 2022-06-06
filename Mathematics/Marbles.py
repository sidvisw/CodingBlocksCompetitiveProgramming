t=int(input())
for i in range(t):
    n,k=map(int,input().split())
    factn_1=1
    factk_1=1
    factn_k=1
    for j in range(2,n):
        factn_1*=j
    for j in range(2,k):
        factk_1*=j
    for j in range(2,n-k+1):
        factn_k*=j
    print(int(factn_1//(factk_1*factn_k)))