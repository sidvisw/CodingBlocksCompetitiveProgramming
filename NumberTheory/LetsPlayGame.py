def CountPower(n,p):
    count=0
    while n//p!=0:
        count+=n//p
        p*=p
    return count
    
if __name__=='__main__':
    n=int(input())
    sieve=[]
    for i in range(2,n+1):
        sieve.append(i)
    for i in range(2,n+1):
        if i in sieve:
            for j in range(i+i,n+1,i):
                if j in sieve:
                    sieve.remove(j)
    ans=0
    for i in range(1,n+1):
        cnt=0
        for num in sieve:
            if CountPower(i,num):
                cnt+=1
        if i==1:
            continue
        ans+=2**(cnt-1)
    print(ans)