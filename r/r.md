# Data structures in R

## Vector
One dimension array which contains **same type element**.
Function *c()* and "*1:12*" (for example) will generate vectors.
```r
> x <- 1:3
int [1:3] 1 2 3
> x <- c('a', 'b')
chr [1:2] "a" "b"
```

## Matrix
Two dimension data structure which contains **same type element** . Function *matrix()* is used to created it.
```r
> matrix(1:9, nrow = 3, ncol = 3)
     [,1] [,2] [,3]
[1,]    1    4    7
[2,]    2    5    8
[3,]    3    6    9
> a <- 1:3
> b <- 1:3
> mat <- cbind("row-1" = a,"row-2" =  b)
     row-1 row-2
[1,]     1     4
[2,]     2     5
[3,]     3     6
> str(mat)
int [1:3, 1:2] 1 2 3 4 5 6
 - attr(*, "dimnames")=List of 2
  ..$ : NULL
  ..$ : chr [1:2] "row-1" "row-2"
```
## List
This data structure includes data of **different types**. It is similar to vector but a vector contains similar data but list contains mixed data. A list is created using *list()*.
```r
> x <- list("a" = 2.5, "b" = TRUE, "c" = 1:3)
$a
[1] 2.5

$b
[1] TRUE

$c
[1] 1 2 3
> str(x)
List of 3
 $ a: num 2.5
 $ b: logi TRUE
 $ c: int [1:3] 1 2 3
```
## Data Frame
This data structure is a **special case of list** where each component is of **same length**. Data frame is created using *frame()* function.
```r
> x <- data.frame("SN" = 1:2, "Age" = c(21,15), "Name" = c("John","Dora"))
  SN Age Name
1  1  21 John
2  2  15 Dora
> str(x)
'data.frame':   2 obs. of  3 variables:
 $ SN  : int  1 2
 $ Age : num  21 15
 $ Name: Factor w/ 2 levels "Dora","John": 2 1

```

## Factor
 Factors are used to store **predefined and categorical data**. It can be created using *factor()* function.
```r
> x <- factor(c("single", "married", "married", "single"), levels = c("single", "married", "divorced"));
> x
[1] single  married married single
Levels: single married divorced
```
 



