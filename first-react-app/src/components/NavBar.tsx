import '../../css/styles.css'
import NavBarLinks from './NavBarLinks';

interface linkObjekts {
    id: number;
    linkTitle: string;
    linkSrc: string;
}

interface NavBarProps {
    pageTitle: string;
    pageLinks: linkObjekts[];
}

export default function NavBar( props: NavBarProps ) {
    return (
        <div className="navBarContainer">
            <div className="navBarTitleContainer">
                <h1 className="pageTitle">{ props.pageTitle }</h1>
            </div>
            <div className="navBarLinksContainer">
                {props.pageLinks.map(link => (
                    <NavBarLinks key={link.id} linkTitle={link.linkTitle} linkSrc={link.linkSrc}></NavBarLinks>
                ))}
            </div>
            <hr />
        </div>
    );
}
