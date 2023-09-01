import { useState, useEffect } from 'react';
import '../../css/styles.css'

interface Button {
    id: number;
    occupation: string;
}

export default function TicTacToeGame() {
    const [buttons, setButtons] = useState([
        { id: 1, occupation: "" },
        { id: 2, occupation: "" },
        { id: 3, occupation: "" },
        { id: 4, occupation: "" },
        { id: 5, occupation: "" },
        { id: 6, occupation: "" },
        { id: 7, occupation: "" },
        { id: 8, occupation: "" },
        { id: 9, occupation: "" },
    ]);

    const [playerXIsNext, setPlayerXIsNext] = useState(true);
    const [winner, setWinner] = useState('');
    const [buttonClickable, setButtonClickable] = useState(true);

    function handleButtonClick(button: Button) {
        if (button.occupation === '') {
            const newOccupation = playerXIsNext ? 'X' : 'O';
            const updatedButtons = buttons.map((btn) =>
                btn.id === button.id ? { ...btn, occupation: newOccupation } : btn
            );

            setButtons(updatedButtons);
            setPlayerXIsNext(!playerXIsNext);
        }
    }

    useEffect(() => {
        if (
            (buttons[0].occupation === 'X' && buttons[1].occupation === 'X' && buttons[2].occupation === 'X') ||
            (buttons[3].occupation === 'X' && buttons[4].occupation === 'X' && buttons[5].occupation === 'X') ||
            (buttons[6].occupation === 'X' && buttons[7].occupation === 'X' && buttons[8].occupation === 'X') ||
            (buttons[0].occupation === 'X' && buttons[3].occupation === 'X' && buttons[6].occupation === 'X') ||
            (buttons[1].occupation === 'X' && buttons[4].occupation === 'X' && buttons[7].occupation === 'X') ||
            (buttons[2].occupation === 'X' && buttons[5].occupation === 'X' && buttons[8].occupation === 'X') ||
            (buttons[0].occupation === 'X' && buttons[4].occupation === 'X' && buttons[8].occupation === 'X') ||
            (buttons[2].occupation === 'X' && buttons[4].occupation === 'X' && buttons[6].occupation === 'X')
        ) {
            setWinner('X');
            setButtonClickable(false)
        } else if (
            (buttons[0].occupation === 'O' && buttons[1].occupation === 'O' && buttons[2].occupation === 'O') ||
            (buttons[3].occupation === 'O' && buttons[4].occupation === 'O' && buttons[5].occupation === 'O') ||
            (buttons[6].occupation === 'O' && buttons[7].occupation === 'O' && buttons[8].occupation === 'O') ||
            (buttons[0].occupation === 'O' && buttons[3].occupation === 'O' && buttons[6].occupation === 'O') ||
            (buttons[1].occupation === 'O' && buttons[4].occupation === 'O' && buttons[7].occupation === 'O') ||
            (buttons[2].occupation === 'O' && buttons[5].occupation === 'O' && buttons[8].occupation === 'O') ||
            (buttons[0].occupation === 'O' && buttons[4].occupation === 'O' && buttons[8].occupation === 'O') ||
            (buttons[2].occupation === 'O' && buttons[4].occupation === 'O' && buttons[6].occupation === 'O')
        ) {
            setWinner('O');
            setButtonClickable(false)
        }
        else if (
            buttons[0].occupation != '' &&
            buttons[1].occupation != '' &&
            buttons[2].occupation != '' &&
            buttons[3].occupation != '' &&
            buttons[4].occupation != '' &&
            buttons[5].occupation != '' &&
            buttons[6].occupation != '' &&
            buttons[7].occupation != '' &&
            buttons[8].occupation != ''
        ) {
            setWinner('Tie')
        }
    }, [buttons]);

    function handleReset() {
        const resetButtons = buttons.map((btn) => ({ ...btn, occupation: '' }));
        setButtons(resetButtons);
        setWinner('');
        setPlayerXIsNext(true);
        setButtonClickable(true)
    }

    return (
        <>
            <div className="ticTacToeContainer">
                <div className="ticTacToeGame">
                    {buttons.map((button) => (
                        <button className={`ticTacToeButtons ${!buttonClickable ? 'preventClick' : ''}`} onClick={() => handleButtonClick(button)}>{button.occupation}</button>
                    ))}
                </div>
            </div>
            <h2 className="ticTacToeWinnerText">Winner: {winner}</h2>
            <button className="ticTacToeResetButton" onClick={handleReset}>RESET</button>
        </>
    );
}
