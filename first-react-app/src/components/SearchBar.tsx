import { useState } from 'react'
import '../../css/styles.css'

export default function SearchBar() {
    const [input, setInput] = useState("");
    const urlPreFix = 'http://localhost:5173/'


    function handleInput() {
        const lowercaseString = input.toLocaleLowerCase();
        const currentUrl = window.location.href;
        const regex = new RegExp([...input.toLowerCase()].map(letter => `(?=.*${letter})`).join(''), 'i');


        if (currentUrl === urlPreFix + 'index.html') {
            if (regex.test('home')) {
                return 'index.html'
            } else if (regex.test('socials') || regex.test('github') || regex.test('instagram') || regex.test('onlyfans') || regex.test('contact')) {
                return 'html/socials.html'
            } else if (regex.test('games') || regex.test('tictactoe')) {
                return 'html/games.html'
            } else if (regex.test('')) {
                return 'https://www.youtube.com/watch?v=dQw4w9WgXcQ'
            }
        } else {
            if (regex.test('home')) {
                return '../index.html'
            } else if (regex.test('socials') || regex.test('github') || regex.test('instagram') || regex.test('onlyfans') || regex.test('contact')) {
                return 'socials.html'
            } else if (regex.test('games') || regex.test('tictactoe')) {
                return 'games.html'
            }
        }

    }

    function handleClick() {
        const formattetInput = handleInput()
        const nextPage = formattetInput + ''

        window.location.href = nextPage;
    }

    const handleKeyPress = (event: React.KeyboardEvent<HTMLInputElement>) => {
        if (event.key === 'Enter') {
            event.preventDefault();
            handleClick();
        }

    }

    return (
        <>
            <div className="searchBarContainer">
                <input type="search" className="searchBarInput" onChange={(e) => setInput(e.target.value)} onKeyDown={handleKeyPress} />
                <button type="submit" className="searchBarSubmitButton" onClick={handleClick}>SEARCH</button>
            </div>
        </>
    )
}
