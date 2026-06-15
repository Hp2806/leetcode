# String Compression
def compress(s):
    result = ""
    count = 1

    for i in range(1, len(s)):
        if s[i] == s[i - 1]:
            count += 1
        else:
            result += s[i - 1]
            if count > 1:
                result += str(count)
            count = 1

    result += s[-1]
    if count > 1:
        result += str(count)
    return result
def decompress(s):
    result = ""
    i = 0

    while i < len(s):
        ch = s[i]
        i += 1
        num = ""
        while i < len(s) and s[i].isdigit():
            num += s[i]
            i += 1
        if num:
            result += ch * int(num)
        else:
            result += ch
    return result
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
def isBST(root, min_val=float('-inf'), max_val=float('inf')):
    if root is None:
        return True

    if root.data <= min_val or root.data >= max_val:
        return False

    return (isBST(root.left, min_val, root.data) and
            isBST(root.right, root.data, max_val))
s = "AAACCCBBD"
compressed = compress(s)
print("Original:", s)
print("Compressed:", compressed)
print("Decompressed:", decompress(compressed))
root = Node(2)
root.left = Node(1)
root.right = Node(3)
print("BST Output:", 1 if isBST(root) else 0)
