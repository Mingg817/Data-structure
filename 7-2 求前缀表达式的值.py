data = input().split(" ")

stack = []

def num_fu(e):
    if e == "+" or e == "-" or e == "*" or e == "/":
        return False
    else:
        return True

def Cal():
    q=stack.pop()
    p=stack.pop() 
    fu=stack.pop()
    out=eval(p+fu+q)
    stack.append(str(out))
    if (len(stack)>2 and num_fu(stack[-2])):
        Cal()

try:
    for i in data:
        if (stack == []):
            stack.append(i)
            continue
        if (num_fu(stack[-1])==False or num_fu(stack[-1])==True and num_fu(i)==False):
            stack.append(i)
            continue
        if (num_fu(stack[-1])==True and num_fu(i)==True):
            stack.append(i)
            Cal()
            continue        
    print("{0:.1f}".format(eval(stack[-1])))
except:
    print("ERROR")
