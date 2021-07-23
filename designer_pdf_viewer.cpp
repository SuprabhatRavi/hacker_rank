/*
When a contiguous block of text is selected in a PDF viewer, the selection is highlighted with a blue rectangle. In this PDF viewer, 
each word is highlighted independently. For example: There is a list of 26 character heights aligned by index to their letters. 
For example, 'a' is at index 0 and 'z' is at index 25. There will also be a string. Using the letter heights given, determine the 
area of the rectangle highlight in mm*mm assuming all letters are 1mm wide.
*/

int designerPdfViewer(vector<int> h, string word) 
{
    int n=word.length();
    int Max=1;
    for(int i=0;i<word.length();i++)
    {
        Max=max(Max,h[word[i]%97]);
    }
    return (n)*Max;
}
