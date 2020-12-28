# ft_cub3d
This project is inspired by the world-famous eponymous 90's game, which was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to make a dynamic view inside a maze, in which you'll have to find your way.

<a href="https://ibb.co/8zhm9sG"><img src="https://i.ibb.co/mvxR4Td/Screen-Shot-2020-12-27-at-8-15-31-PM.png" alt="Screen-Shot-2020-12-27-at-8-15-31-PM" border="0"></a>

# DDA-algorithm

In this way, we calculate the length to the wall for each pixel in width. I used https://lodev.org/cgtutor/raycasting.html manual for example.

For the first step, imagine the map 

          {
            1111111111
            1000000001
            1000000N01
            1000100001
            1001111111
            1111111111
          }
like a chessboard

Next step is understanding, that player has only 1 ray of direction, but we must increase with Field Of View (FOV).
