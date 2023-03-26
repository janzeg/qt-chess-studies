#ifndef CHESSALGORITHM_H
#define CHESSALGORITHM_H

#include <QObject>
#include "chessboard.h"

class ChessAlgorithm : public QObject
{
    Q_OBJECT
    Q_ENUMS(Result Player)
    Q_PROPERTY(Result result READ result CONSTANT)
    Q_PROPERTY(Player currentPlayer READ currentPlayer NOTIFY currentPlayerChanged)

public:
    enum Result { NoResult, Player1Wins, Draw, Player2Wins };
    enum Player { NoPlayer, Player1, Player2 };

    explicit ChessAlgorithm(QObject *parent = 0);
    ChessBoard* board() const;
    inline Result result() const { return m_result; }
    inline Player currentPlayer() const { return m_currentPlayer; }

    //bool move(int colFrom, int rankFrom, int colTo, int rankTo); // Nie wiem czy public
    //bool move(const QPoint &from, const QPoint &to);


signals:
    void boardChanged(ChessBoard*);
    void gameOver(ChessAlgorithm::Result);
    void currentPlayerChanged(ChessAlgorithm::Player);

public slots:
    virtual void newGame();
    virtual bool move(int colFrom, int rankFrom, int colTo, int rankTo);
    bool move(const QPoint &from, const QPoint &to);

protected:
    virtual void setupBoard();
    void setBoard(ChessBoard *board);
    void setResult(Result);
    void setCurrentPlayer(Player);

private:
    ChessBoard* m_board;
    Result m_result;
    Player m_currentPlayer;
};

#endif // CHESSALGORITHM_H
