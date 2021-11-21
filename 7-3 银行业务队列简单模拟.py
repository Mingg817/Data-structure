data=list(map(int,input().split(" ")))
N=data.pop(0)
A=[]
B=[]

for i in data:
    if i%2==1:
        A.append(i)
    else:
        B.append(i)

def Out():
    if A!=[] and B!=[]:
        print(A.pop(0),A.pop(0),end="")
        print(" ",end="")
        print(B.pop(0),end="")
        if not(A==[] and B==[]):
            print(" ",end="")
        Out()
    if A==[] and B!=[]:
        for i in B:
            print(B.pop(0),end="")
            if B!= []:
                print(" ",end="")
    if A!=[] and B==[]:
        for i in A:
            print(A.pop(0),end="")
            if A!= []:
                print(" ",end="")

Out()

