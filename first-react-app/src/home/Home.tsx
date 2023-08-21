import NavBar from '../components/NavBar'
import '../../css/styles.css'

export default function App() {
  const pageLinks = [
    {id: 1, linkTitle: 'CAREER', linkSrc: 'career.html'},
    {id: 2, linkTitle: 'ABOUT', linkSrc: 'about.html'},
    {id: 3, linkTitle: 'HOME', linkSrc: 'index.html'},
    {id: 4, linkTitle: 'SPORT', linkSrc: 'sport.html'},
    {id: 5, linkTitle: 'SOCIALS', linkSrc: '/html/socials.html'}
  ]
  return (
    <>
      <NavBar pageTitle="HOME" pageLinks={pageLinks}></NavBar>
    </>
  )
}
