int numComponents(struct ListNode* head, int* nums, int numsSize) {
    int count = 0;

    while(head) {
        int found = 0;

        for(int i = 0; i < numsSize; i++) {
            if(nums[i] == head->val) {
                found = 1;
                break;
            }
        }

        if(found) {
            if(head->next == NULL) {
                count++;
            } else {
                int nextFound = 0;

                for(int i = 0; i < numsSize; i++) {
                    if(nums[i] == head->next->val) {
                        nextFound = 1;
                        break;
                    }
                }

                if(!nextFound)
                    count++;
            }
        }

        head = head->next;
    }

    return count;
}