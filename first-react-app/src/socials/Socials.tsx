import NavBar from '../components/NavBar'
import SocialCard from '../components/SocialCard'
import '../../css/styles.css'

export default function Socials() {
  const pageLinks = [
    {id: 1, linkTitle: 'CAREER', linkSrc: 'career.html'},
    {id: 2, linkTitle: 'ABOUT', linkSrc: 'about.html'},
    {id: 3, linkTitle: 'HOME', linkSrc: '../../index.html'},
    {id: 4, linkTitle: 'GAMES', linkSrc: 'games.html'},
    {id: 5, linkTitle: 'SOCIALS', linkSrc: 'socials.html'}
  ]

  const socialCard = [
    {
      id: 1,
      socialName: 'INSTAGRAM',
      socialLogo: 'https://www.transparentpng.com/thumb/logo-instagram/YfpFOL-logo-instagram-free-transparent.png',
      socialUsername: 'luis.txh',
      socialLink: 'https://www.instagram.com/luis.txh/'
    },
    {
      id: 2,
      socialName: 'GITHUB',
      socialLogo: '../../assets/github-logo.png',
      socialUsername: 'Luis Thieme',
      socialLink: 'https://github.com/luisthieme'
    },
    {
      id: 3,
      socialName: 'ONLYFANS',
      socialLogo: '../../assets/winking-jesus.gif',
      socialUsername: 'Naughty Jesus 69',
      socialLink: 'https://www.youtube.com/watch?v=dQw4w9WgXcQ'
    }
  ]

  return (
    <>
      <NavBar pageTitle="SOCIALS" pageLinks={ pageLinks }></NavBar>
      <div className="mainContainerSocials">
        <div className="socialCardGridContainer">
          <SocialCard socialCard={ socialCard }></SocialCard>
        </div>
      </div>
    </>
  )
}
