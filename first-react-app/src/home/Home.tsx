import NavBar from '../components/NavBar'
import '../../css/styles.css'
import { BrowserRouter as Router, Route, Switch } from 'react-router-dom';

export default function App() {
  const pageLinks = [
    {id: 1, linkTitle: 'CAREER', linkSrc: 'career.html'},
    {id: 2, linkTitle: 'ABOUT', linkSrc: 'about.html'},
    {id: 3, linkTitle: 'HOME', linkSrc: 'index.html'},
    {id: 4, linkTitle: 'GAMES', linkSrc: '/html/games.html'},
    {id: 5, linkTitle: 'SOCIALS', linkSrc: '/html/socials.html'}
  ]
  return (
    <>
      <NavBar pageTitle="HOME" pageLinks={pageLinks}></NavBar>
    </>
  )
}
