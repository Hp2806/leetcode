from typing import Optional

class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        prev = dummy
        
        # Ensure there are at least two nodes ahead to swap
        while prev.next and prev.next.next:
            first = prev.next
            second = prev.next.next
            
            # Rewire pointers to swap `first` and `second`
            prev.next = second
            first.next = second.next
            second.next = first
            
            # Advance `prev` to the end of the swapped pair (`first`)
            prev = first
            
        return dummy.next
