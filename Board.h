class Board {
public:
  Board(int* initialBoard);
  virtual ~Board();

  bool IsMoveLegal(int col, int row, int num);

  bool Solve();
  bool RecursiveSolve(int col, int row, int num);

  void Print();

protected:
  Board() {}

  int m_Board[9][9]; // Col, row
};
