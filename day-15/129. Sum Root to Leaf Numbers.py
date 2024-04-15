class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def sumNumbers(self, root: TreeNode, initVal: int = 0) -> int:
        if root is None:
            return 0
        if root.left is None and root.right is None:
            # leaf node
            return initVal + root.val
        
        # non-leaf node
        # accumulate the score from left and right subtrees
        sum = 0
        if root.left:
            sum += self.sumNumbers(root.left, (initVal + root.val) * 10)
        if root.right:
            sum += self.sumNumbers(root.right, (initVal + root.val) * 10)
        
        return sum
