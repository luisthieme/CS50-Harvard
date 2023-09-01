import '../../css/styles.css'
import NavBar from '../components/NavBar'

export default function Games() {
    const pageLinks = [
        { id: 1, linkTitle: 'CAREER', linkSrc: 'career.html' },
        { id: 2, linkTitle: 'ABOUT', linkSrc: 'about.html' },
        { id: 3, linkTitle: 'HOME', linkSrc: '../../index.html' },
        { id: 4, linkTitle: 'GAMES', linkSrc: 'games.html' },
        { id: 5, linkTitle: 'SOCIALS', linkSrc: 'socials.html' }
    ]

    return (
        <>
            <NavBar pageTitle="CAREER" pageLinks={pageLinks}></NavBar>
        </>
    );
}