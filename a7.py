class Node:
    def __init__(self, data):
        self.data = data
        self.left = None   # Previous pointer in DLL
        self.right = None  # Next pointer in DLL


class Solution:
    def __init__(self):
        self.prev = None
        self.head = None

    def bToDLL(self, root):
        if root is None:
            return
        self.bToDLL(root.left)

        if self.prev is None:
            self.head = root
        else:
            root.left = self.prev
            self.prev.right = root

        self.prev = root

        self.bToDLL(root.right)

        return self.head
root = Node(10)
root.left = Node(20)
root.right = Node(30)
root.left.left = Node(40)
root.left.right = Node(60)
obj = Solution()
head = obj.bToDLL(root)
temp = head
last = None
while temp:
    print(temp.data, end=" ")
    last = temp
    temp = temp.right
print()
while last:
    print(last.data, end=" ")
    last = last.left
