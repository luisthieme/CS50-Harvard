import '../../css/styles.css'

export default function SearchBar() {
    return (
        <>
            <div className="searchBarContainer">
                <input type="search" className="searchBarInput"/>
                <button type="submit" className="searchBarSubmitButton">SEARCH</button>
            </div>
            
        </>
    )
}
