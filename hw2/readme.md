Thomas Tseng
1339907 tgents


1. popular.txt might not contain exactly 100 urls. Is it a bug in your script or a bug in the data? Explain how you chose to handle any extra urls.

> I got 100 URLs. Though I had to remove the extra ones that were on the page, which seems to be the next question.

2. There are some URLs at the beginning and at the end of the file (such as http://www.100bestwebsites.org/criteria) that are not actually part of the list of 100 best web sites. It's up to you to figure out a reasonable way to handle this so they don't get included in the output - either by removing them somehow (by hand? with some sort of script?), or leaving them in and figuring out how best to deal with them. Explain what you did and why. This shouldn't be extensive or long-winded, just a few sentences about what the problem was and how you dealt with it.

> I basically just looked at the urls and tried ones that were not supposed to be on the list. First, it looked like the sight was pulling from babelfish a lot and referencing its own site, so used sed to remove those. I also noticed they were linking to Wikipedia for more information on some sites, so I used sed to remove those as well by finding anything containing "/wiki/". I did the same for "babelfish" and "100best".


1. Examine the gnuplot file produce-scatterplot.gnuplot. Ignoring the first line, explain what the rest of the script does.

> set xlabel "Rank" -- sets label for x-axis as "rank"
set ylabel "Size (Bytes)" -- sets label for y-axis as "size"
set xrange [0:100] -- sets the range of x from 0 to 100
set output "scatterplot.eps" --outputs the plot to "scatterplot.eps"
plot "results.txt" using 1:3 title "" with points -- plots data from results.txt, uses columns 1 and 3 for x and y respectively. title is set as blank, plot using points.

2. Looking at the scatterplot, what can you conclude about the relationship between the popularity of a site and the size of its index.html file? Are these result what you expected? 

> Looks like there is no real correlation between popularity and the size of its homepage. I kind of did expect this since homepages are usually different for different sites, resulting in them having varying sizes.