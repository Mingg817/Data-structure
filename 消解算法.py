def input_L():
    input()
    L = []
    l = []
    while True:
        l = input().split(" ")
        l = list(map(int, l))
        l = tuple(l)
        if (l != (0, 0)):
            L.append(l[:-1])
        else:
            break
    print(L)
    return L


def Res(C_1, C_2):
    Res_d = 0
    C_1=set(C_1)
    C_2=set(C_2)
    for i in C_1.copy():
        for j in C_2.copy():
            if i == -j:
                C_1.remove(i)
                C_2.remove(j)
                Res_d = 1
    if Res_d == 1:
        #print(C_1 | C_2)
        return tuple(C_1 | C_2)
    else:
        #print("None")
        return None


def xiaojie():
    S = input_L()
    S_0 = set()
    S_2 = set()
    S_1 = set(S)
    while(True):
        for i in S_0.copy():
            for j in S_1.copy():
                C = Res(i, j)
                if C != None:
                    if C == ():
                        print("no")
                        return None
                    if (C not in S_0) and (C not in S_1):
                        S_2.add(C)

        for i in S_1.copy():
            for j in S_1.copy():
                C = Res(i, j)
                if C != None:
                    if C == ():
                        print("No",end="")
                        return None
                    if (C not in S_0) and (C not in S_1):
                        S_2.add(C)
        
        if S_2==set():
            print("Yes",end="")
            return None
        else:
            S_0 |=S_1
            S_1=S_2.copy()
            S_2.clear()


xiaojie()
