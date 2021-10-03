n=eval(input())
for i in range(n): 
    line=list(map(str,input().split()))
    p=eval(line[0])/eval(line[1])
    q=eval(line[2])/eval(line[3])
    r=eval(line[4])/eval(line[5])
    print( "{:.4}".format( (r*p)/((r*p) + ((1-r))*(1-q))))