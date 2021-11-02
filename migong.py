class migong:
    def __init__(self,maps) :
        self.maps=maps
        self.x=1
        self.y=1
        self.stack=[[1,1]]
    
    def whatnext(self):
        lens=len(self.maps[0])-2
        if self.stack[-1]==[lens,lens]:
            return self.print_step()

        if self.maps[self.x-1][self.y]==0:
            self.maps[self.x][self.y]=-1
            self.x-=1
            self.stack.append([self.x,self.y])

        elif self.maps[self.x][self.y+1]==0:
            self.maps[self.x][self.y]=-1
            self.y+=1
            self.stack.append([self.x,self.y])

        elif self.maps[self.x+1][self.y]==0:
            self.maps[self.x][self.y]=-1
            self.x+=1
            self.stack.append([self.x,self.y])

        elif self.maps[self.x][self.y-1]==0:
            self.maps[self.x][self.y]=-1
            self.y-=1
            self.stack.append([self.x,self.y])
 
        else:
            self.maps[self.x][self.y]=-1
            self.stack.pop()
            self.x=self.stack[-1][0]
            self.y=self.stack[-1][1]
        
        return self.whatnext()

    def print_step(self):
        for i in self.stack:
            i=str(tuple(i))
            print(i.replace(" ",""),end="")
            #由于元祖输出会有奇怪的空格，为了匹配格式，先转换为str，再删掉奇怪的空格
        
#如果传入的不带边界
def add_edge(maps):
    lens=len(maps[0])
    m=[]
    m.append([1]*(lens+2))
    for i in maps:
        m.append([1]+i+[1])
    m.append([1]*(lens+2))
    return m

def main():
    maps="""[{1,1,1,1,1,1,1,1,1,1},
             {1,0,0,1,0,0,0,1,0,1},
             {1,0,0,1,0,0,0,1,0,1},
             {1,0,0,0,0,1,1,0,0,1},
             {1,0,1,1,1,0,0,0,0,1},
             {1,0,0,0,1,0,0,0,0,1},
             {1,0,1,0,0,0,1,0,0,1},
             {1,0,1,1,1,0,1,1,0,1},
             {1,1,0,0,0,0,0,0,0,1},
             {1,1,1,1,1,1,1,1,1,1}]"""

    #以C++的{}传入，需要改成python的list[]
    going=migong(eval(maps.replace("{","[").replace("}","]")))
    going.whatnext()

main()