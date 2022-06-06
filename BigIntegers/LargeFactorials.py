def factorial(n):
    ans=1
    for i in range(1,n+1):
        ans*=i
    return ans
t=int(input())
while(t>0):
    n=int(input())
    print(factorial(n))
    t-=1
