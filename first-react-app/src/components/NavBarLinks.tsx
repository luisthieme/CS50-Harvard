import '../../css/styles.css'

interface NavBarLinksProps {
    linkTitle: string,
    linkSrc: string,
    key: number
}

export default function NavBarLinks( props: NavBarLinksProps) {
    return <a className="navBarLinks" href={ props.linkSrc } key={props.key}>{ props.linkTitle }</a>;
}
