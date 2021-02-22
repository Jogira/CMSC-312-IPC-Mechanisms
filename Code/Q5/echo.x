/*
 * The average procedure receives an array of real
 * numbers and returns the average of their
 * values. This toy service handles a maximum of
 * 100 numbers.
 * http://www.linuxjournal.com/article/2204?page=0,1
 */


struct word
{
            char a[120];
};
program ECHO_PROG
{
            version ECHO_VERS
            {
                        word ECHO(word)=1;           
            }=1;
}=6319;