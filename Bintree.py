class Bintree():
    def __init__(self,data=None,left=None,right=None):
        self.data=data
        self.left=left
        self.right=right

def kuohao(tree) -> None:
#    tree=Bintree()
    print(tree.data,end="")
    if tree.left != None and tree.right ==None:
        print("(",end="")
        kuohao(tree.left)
        print(")",end="")
    if tree.left ==None and tree.right != None:
        print("(,",end="")
        kuohao(tree.right)
        print(")",end="")
    if tree.left !=None and tree.right != None:
        print("(",end="")
        kuohao(tree.left)
        print(",",end="")
        kuohao(tree.right)
        print(")",end="")


def change(behind,middle,Tr,left_right) -> None:
    '''
    
    利用change函数，将数列拆分并添加相应的结点到二叉数上

    Args:
        behind:传入后序数组
        middle:传入中序数组
        Tr:后序数组往Tr这个结点上加子结点
        left_right:往Tr左或者右加结点，1是left，2是right，0是root
        
    '''
    if left_right == 0:#此时为根节点
        Tr.data=behind[-1]
    if left_right == 1:#意思是在Tr左边添加
        Tr.left=Bintree(behind[-1])
        Tr=Tr.left
    if left_right == 2:#意思是在Tr右边添加
        Tr.right=Bintree(behind[-1])
        Tr=Tr.right

    #切割middle中序数组
    prev=behind[-1] #prev是上面被加入树的值
    posi_prev=middle.index(prev)
    m_left=middle[:posi_prev]
    m_right=middle[posi_prev+1:]

    if len(m_left)==1:
        Node=Bintree(m_left[0])
        Tr.left=Node
    if len(m_right)==1:
        Node=Bintree(m_right[0])
        Tr.right=Node
    if len(m_left)>1:
        change(behind[0:len(m_left)],m_left,Tr,1)
    if len(m_right)>1:
        change(behind[len(m_left):len(m_left)+len(m_right)],m_right,Tr,2)

behind=list(input("behind:"))
middle=list(input("middle:"))
Tree=Bintree()
change(behind,middle,Tree,0)
kuohao(Tree)