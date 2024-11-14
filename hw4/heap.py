class heap:

    def __init__(self, val , left = None , right = None , f = None , attr = min):
        self.val = val
        self.left = left
        self.right = right
        self.f = f
        self.attr = attr

    def build(self , buildList):
        p = [self]
        x = p.pop(0)
        while len(buildList):
            
            if x.left == None:
                x.left = heap(buildList.pop(0))
                x.left.f = x
                p.append(x.left)
            elif x.right == None:
                x.right = heap(buildList.pop(0))
                x.right.f = x
                p.append(x.right)
                x = p.pop(0)
            
            
    

    def display(self , sep = " "):
        p = [self]
        while len(p):
            x = p.pop(0)
            print(x.val , end='|')
            if x.left : p.append(x.left)
            if x.right: p.append(x.right)
        print()

    def findLast(self):
        p = [self]
        x = None
        while len(p):
            last = x
            x = p.pop(0)
            if x.left : p.append(x.left)
            else: return last.right
            if x.right: p.append(x.right)
            else: return x.left

        
    
    def insert(self , target):

        print(f"|+{target}",end='|')

        p = [self]
        while 1:
            x = p.pop(0)
            if x.left:
                p.append(x.left)
                if x.right:
                    p.append(x.right)
                else:
                    x.right = heap(target)
                    target = x.right
                    target.f = x
                    break
            else:
                x.left = heap(target)
                target = x.left
                target.f = x
                break
        
        while target.f:
            if self.attr(target.f.val , target.val) == target.val:
                target.f.val , target.val = target.val , target.f.val
                target = target.f
            else:
                break


    def extract(self):

        print("|-min|",end='')

        toSwitch = self.findLast()
        self.val , toSwitch.val = toSwitch.val , self.val

        #print(self.val)
        
        if toSwitch.f.right:
            toSwitch.f.right = None
        else:
            toSwitch.f.left = None


        self.heapify()

    def heapify(self):

        '''
        DEBUGGER = self
        while DEBUGGER.f:
            DEBUGGER = DEBUGGER.f 
        
        DEBUGGER.display()

        try: print(self.val , self.left.val , self.right.val)
        except: pass
        '''

        if self.left and self.right:
            if self.attr(self.val , self.left.val , self.right.val) == self.left.val:
                self.left.val , self.val = self.val , self.left.val
                self.left.heapify()
            elif self.attr(self.val , self.left.val , self.right.val) == self.right.val:
                self.right.val , self.val = self.val , self.right.val
                self.right.heapify()
            
            

        elif self.left:
            if self.attr(self.val , self.left.val) == self.left.val:
                self.left.val , self.val = self.val , self.left.val
                self.left.heapify()
        
        elif self.right:
            if self.attr(self.val , self.right.val) == self.right.val:
                self.right.val , self.val = self.val , self.right.val
                self.right.heapify()
        
        


def buildHeap(arr):

    root = heap(arr.pop(0))
    root.build(arr)
    return root

    

if __name__ == '__main__':

    root = buildHeap([20,25,30,35,28,50,65,45,50,43])
    root.display()
    root.extract()
    root.display()
    root.insert(24)
    root.display()
    root.extract()
    root.display()
    root.insert(12)
    root.display()
    root.extract()
    root.display()
    root.insert(60)
    root.display()

