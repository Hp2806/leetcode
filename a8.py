class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
def checkLeaves(root):
    leaf_level = [-1]  
    def dfs(node, level):
        if node is None:
            return True
        if node.left is None and node.right is None:
            if leaf_level[0] == -1:
                leaf_level[0] = level
                return True
            return level == leaf_level[0]

        return dfs(node.left, level + 1) and dfs(node.right, level + 1)

    return 1 if dfs(root, 0) else 0
root1 = Node(1)
root1.left = Node(2)
root1.right = Node(3)

print(checkLeaves(root1))  # Output: 1

root2 = Node(10)
root2.left = Node(20)
root2.right = Node(30)
root2.left.left = Node(10)
root2.left.right = Node(15)

print(checkLeaves(root2))  # Output: 0
