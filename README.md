# tail
The 'Tail' command is a utility that retrieves and prints the last N lines of a given input. By default, it displays the last 10 lines of specified files. If multiple file names are provided, the data from each file is shown alongside its respective filename. When no filename is specified, 'tail' reads from the standard input.

Usage in XV6: 

-n: Prints the last n lines of each file.

For the given tail.c and tail.txt files, the output for various commands should work as demonstrated below.

1. $tail tail.txt

   Output: (The last 10 lines of the textfile are printed on the output console by default if n is specified)
   
   Regardless of the kind of information they contain, all paragraphs share certain characteristics.

   One of the most important of these is a topic sentence.

   A well-organized paragraph supports or develops a single controlling idea, which is expressed in a sentence called the topic sentence.

   A topic sentence has several important functions: it substantiates or supports an essay’s thesis statement.

   Readers generally look to the first few sentences.

   That’s why it’s often best to put the topic sentence at the very beginning of the paragraph.

   In some cases, however, it’s more effective to place another sentence before the topic sentence.

   Although most paragraphs should have a topic sentence.

   You might be able to omit a topic sentence in a paragraph that narrates a series of events.

   The vast majority of your paragraphs, however, should have a topic sentence.

2. $tail -3 tail.txt

      Output: (The last 3 lines of the textfile should be printed on the output console)

      Although most paragraphs should have a topic sentence.

      You might be able to omit a topic sentence in a paragraph that narrates a series of events.

      The vast majority of your paragraphs, however, should have a topic sentence.
