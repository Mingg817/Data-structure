mnum=eval(input())
l=input().split(" ")
l=list(map(int,l))
max=[]
max_len=0
temp=[-1]
for i in l:
    if i>temp[-1]:
        temp.append(i)
    else:
        if len(temp)-1>max_len:
            max=temp[1:]
            max_len=len(max)
            mnum-=len(max)
        temp=[-1,i]
if (len(temp)==(mnum+1) and len(temp)-1>len(max)):
    max=temp[1:]

max_len=len(max)
j=0
for i in max:
    print("{0}".format(i),end="")
    j+=1
    if j<max_len:
        print(" ",end="")