import '../../css/styles.css'

interface NavBarLinksProps {
    linkTitle: string,
    linkSrc: string,
    key: number
    isActive: boolean
}

export default function NavBarLinks( props: NavBarLinksProps) {
    return <a className={`${ props.isActive ? 'navBarLinkActive' : ''} navBarLinks`}href={ props.linkSrc } key={props.key}>{ props.linkTitle }</a>;
}
