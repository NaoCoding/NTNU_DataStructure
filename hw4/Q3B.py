class n:
    def __init__(self,val,left=None,right=None) -> None:
        self.val = val
        self.left = left
        self.right = right

def pre(p):
    if not p:
        return
    print(p.val,end='')
    pre(p.left)
    pre(p.right)

def ino(p):
    if not p:
        return
    ino(p.left)
    print(p.val,end='')
    ino(p.right)

def post(p):
    if not p:
        return
    post(p.left)
    post(p.right)
    print(p.val,end='')

root = n('A')

root.left = n('B')
root.left.left = n('C')
root.left.left.left = n('E')

root.left.right = n('L')

root.left.right.right = n('G')
root.left.right.right.left = n('F')

root.right = n('H')
root.right.left = n('J')
root.right.left.left = n('I')
root.right.left.left.left = n("K")

root.right.right = n("D")

print("Preorder :",end="")
pre(root)
print()
print("Inorder : ",end='')
ino(root)
print()
print("PostOrder : ",end='')
post(root)
print()