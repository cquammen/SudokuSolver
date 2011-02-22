project( SudokuSolver )
cmake_minimum_required( VERSION 2.4 )

set( SRC
  Main.cxx
  Board.cxx
)

include_directories(
  ${SudokuSolver_SOURCE_DIR}
)

add_executable( SudokuSolver
  ${SRC}
)
