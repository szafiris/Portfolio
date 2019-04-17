-- Some coding practice in Haskell. Done in collaboration with Alexia filler (github: afiller1)
module Warmup
  (change
  , stripQuotes
  , firstUppercasedOverLengthFive
  , sumOfCubesOfOdds
  , powers
  , ThreeDShapes(Box, Sphere)
  , volume
  , surfaceArea
  , swapAdjacents
  )
  where
import Data.Char
import Data.List

change :: Integral d => d -> Either [Char] (d, d, d, d)
change amount =
  if amount < 0 then
    Left "amount cannot be negative"
  else
    let
      (quarters, afterQuarters) = amount `divMod` 25
      (dimes, afterDimes) = afterQuarters `divMod` 10
      (nickels, pennies) = afterDimes `divMod` 5
    in
    Right(quarters, dimes, nickels, pennies)

stripQuotes :: [Char] -> [Char]
stripQuotes s = filter (\c -> c /= '\'' && c /= '"') s

firstUppercasedOverLengthFive :: [[Char]] -> Maybe [Char]
firstUppercasedOverLengthFive words
  | length filteredList == 0 = Nothing
  | otherwise = Just upperCased
  where filteredList = filter(\c -> length c > 5) words
        firstOfFilteredList = head(filteredList)
        upperCased = map toUpper(firstOfFilteredList)

sumOfCubesOfOdds :: Integral c => [c] -> c
sumOfCubesOfOdds = sum . map (^3) . filter odd

powers :: Num a => a -> [a]
powers n = [ n^i | i <- [0 ..]]

swapAdjacents :: [a] -> [a]
swapAdjacents [] = []
swapAdjacents (x:y:xys) = y:x:(swapAdjacents xys)
swapAdjacents [x] = [x]

data ThreeDShapes
    = Sphere Double
    | Box Double Double Double
    deriving (Eq, Show)

volume :: ThreeDShapes -> Double
volume (Sphere r) = (4/3) * pi * (r * r * r)
volume (Box h w l) = h * w * l

surfaceArea :: ThreeDShapes -> Double
surfaceArea (Sphere r) = 4 * pi * (r * r)
surfaceArea (Box h w l) = 2 * ((w * l) + (h * l) + (h * w))
