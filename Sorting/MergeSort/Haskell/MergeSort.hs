sort :: Ord a => [a] -> [a]
sort []   = []
sort [x]  = [x]
sort xs = merge (sort left) (sort right)
  where
    (left, right) = splitAt (length xs `div` 2) xs
    merge [] ys = ys
    merge xs [] = xs
    merge xs'@(x:xs) ys'@(y:ys) = if x < y then x : merge xs ys' else y : merge xs' ys
