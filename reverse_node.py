from typing import Optional
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or k == 1:
            return head
        
        dummy = ListNode(0, head)
        group_prev = dummy
        
        while True:
            # 1. Check if there are at least k nodes remaining
            kth = self._get_kth_node(group_prev, k)
            if not kth:
                break
                
            group_next = kth.next
            
            # 2. Reverse the k nodes in the current group
            prev = group_next
            curr = group_prev.next
            
            while curr != group_next:
                temp = curr.next
                curr.next = prev
                prev = curr
                curr = temp
                
            # 3. Connect the reversed group back to the main list
            # `group_prev.next` was the start of the group and is now its tail
            new_group_tail = group_prev.next
            group_prev.next = kth
            group_prev = new_group_tail
            
        return dummy.next

    def _get_kth_node(self, curr: Optional[ListNode], k: int) -> Optional[ListNode]:
        while curr and k > 0:
            curr = curr.next
            k -= 1
        return curr
