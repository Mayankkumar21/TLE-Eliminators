// https://practice.geeksforgeeks.org/problems/count-of-distinct-substrings/1


class TrieNode {
public:
    bool isWord;
    TrieNode* child[26];
 
    TrieNode()
    {
        isWord = 0;
        for (int i = 0; i < 26; i++) {
            child[i] = 0;
        }
    }
};
int countDistinctSubstring(string str)
{
    //Your code here
    TrieNode* head = new TrieNode();
 
    // will hold the count of unique substrings
    int count = 0;
    // included count of substr " "
 
    for (int i = 0; i < str.length(); i++) {
        TrieNode* temp = head;
 
        for (int j = i; j < str.length(); j++) {
            // when char not present add it to the trie
            if (temp->child[str[j] - 'a'] == NULL) {
                temp->child[str[j] - 'a'] = new TrieNode();
                temp->isWord = 1;
                count++;
            }
            // move on to the next char
            temp = temp->child[str[j] - 'a'];
        }
    }
 
    return count+1;
}
